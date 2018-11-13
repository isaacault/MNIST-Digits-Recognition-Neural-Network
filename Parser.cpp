#include "Parser.h"

Parser::Parser(SharedMem * shmem, vector<string> files, const string path)
{
    DEBUG_PRINT("Parser Constructer");

    if (!path.empty()){
        m_MNISTDataDirectory = path;
    }

    vector<string>::iterator fileIt = files.begin();
    unsigned char buf;

    FILE * fp_images = fopen((m_MNISTDataDirectory + *(fileIt++)).c_str(), "r");
    FILE * fp_labels = fopen((m_MNISTDataDirectory + *(fileIt++)).c_str(), "r");
    if (fp_images == NULL || fp_labels == NULL) {
        cerr << "Error Opening File" << endl;
        abort();
    }

    traversePastHeader(fp_images);
    traversePastHeader(fp_labels);
    
    while (!feof(fp_images) && !feof(fp_labels)) {
        while(!shmem->consumed()) {
            //DEBUG_PRINT("Parser waiting");
            usleep(5000); // this should be modified so that consumer wakes producer
        }
        DEBUG_PRINT("Parser taking action");
        shmem->setConsumed(false);
        do {
            fread(&buf, sizeof(unsigned char), 1, fp_images);
        } while (m_digit.addPixel(buf));
        fread(&buf, sizeof(unsigned char), 1, fp_labels);
        m_digit.setLabel(buf);

        shmem->setDigit(m_digit);


        m_digit.clean();
    }
    fclose(fp_images);
    fclose(fp_labels);
}


void Parser::traversePastHeader(FILE * fp)
{
    unsigned int buf;

    fread(&buf, sizeof(buf), 1, fp);
    unsigned int magic_num = endianSwap(buf);

        /*****************************************************************************
     * The MNIST data begins with a "magic number" which has now been read and 
     * swapped endianness. For the files they provide there are two cases with
     * this number:
     * 
     * Case 1:  magic_num == 2049. In this case the file being read is a label 
     *          file and there is only one more item in the header, the number
     *          of items in the file.
     * Case 2:  magic_num == 2051. In this case the file being read is an image
     *          file and there are 3 more items in the header, the number of
     *          imageshttps://stackoverflow.com/questions/15879761/segmentation-fault-on-fopen, number of rows, and number of columns.
     * 
     * **************************************************************************/

    for (unsigned int i = 2048; i < magic_num; i++) {
        fread(&buf, sizeof(buf), 1, fp);
    }
}


unsigned int Parser::endianSwap(unsigned int c)
{
    return  ((c >> 24) & 0xff) | // move byte 3 to byte 0
            ((c << 8) & 0xff0000) | // move byte 1 to byte 2
            ((c >> 8) & 0xff00) | // move byte 2 to byte 1
            ((c << 24) & 0xff000000); // byte 0 to byte 3 
}
