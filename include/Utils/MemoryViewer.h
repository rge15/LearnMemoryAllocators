#pragma once
#include "TSingleton.h"

class MemoryViewer : public Singleton<MemoryViewer>
{
    public:
        void Render();

        bool IsVisible() { return m_visible; }

        void ChangeVisibility() { m_visible = !m_visible; }

        void SetVisibility( bool p_visible ) { m_visible = p_visible; }
        
    private:
        bool m_visible;

        //Addres to display
        //Bytes to display
        //ETC...

    SINGLETON_CONSTRUCTOR(MemoryViewer)        
};