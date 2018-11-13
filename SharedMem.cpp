#include "SharedMem.h"

SharedMem::SharedMem()
{
    DEBUG_PRINT("SharedMem Constructor");

    m_finishedRead = false;
    m_network = -1;
    m_parser = -1;
    m_consumed = true;
}

void SharedMem::setNetworkPID(pid_t pid)
{
    m_network = pid;
}

void SharedMem::setParserPID(pid_t pid)
{
    m_parser = pid;
}

void SharedMem::setDigit(Digit dig)
{
    sem_wait(m_sem);
    m_digit = dig;
    sem_post(m_sem);
}

pid_t SharedMem::getNetworkPID() { return m_network; }

pid_t SharedMem::getParserPID() { return m_parser; }

Digit SharedMem::getDigit() { return m_digit; }

bool SharedMem::consumed() { return m_consumed; }

void SharedMem::setConsumed(bool val) { m_consumed = val; }