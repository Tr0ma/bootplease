#include "events\EventDispatcher.h"

bool EventDispatcher::HasListener(const char* eventType)
{
    for ( int i = 0 ; i < m_EventCallBacks.size() ; i++)
    {
        const EventCallBackPtr& cb = m_EventCallBacks[i];
        if (cb->GetType() == eventType)
        {
            return true;
        }
    }

    return false;
}

void EventDispatcher::Dispatch(const Event& evt)
{
    for (int i = 0 ; i < m_EventCallBacks.size() ; i++)
    {
        const EventCallBackPtr& cb = m_EventCallBacks[i];
        if (cb->GetType() == evt.GetType())
        {
            cb->Call(evt);
        }
    }
}