

#include <map>
#include <iostream>

template<typename K, typename V>
class interval_map 
{
	V m_valBegin; 
	std::map<K,V> m_map;
public:
	
	interval_map(V const& val)
	: m_valBegin(val)
	{}

	void assign( K const& keyBegin, K const& keyEnd, V const& val ) 
	{
        // check to ensure the value of keyBegin is not lower than keyEnd
        if(keyBegin > keyEnd)
        {
        return;
        }

        auto itrStart = m_map.lower_bound(keyBegin);
        auto itrEnd = m_map.lower_bound(keyEnd);

        if(itrStart == m_map.begin() && itrStart->first > keyBegin )
        {
            if(val != m_valBegin)
                {
                    // set m_valBegin to be equal to val since we have noted it wasn't similar
                    m_valBegin = val;
                }
        }
        else
        {
            --itrStart;
        }

        if(itrStart != m_map.end() && itrStart->second == val)
        {
            m_map.erase(itrStart);
        }

        if (itrEnd != m_map.end() && itrEnd->second == val) 
        {
                m_map.erase(itrEnd);
                ++itrEnd;
        }

        // erase interval
        m_map.erase(itrStart, itrEnd);

        if(val != m_valBegin)
        {
            m_map[keyBegin] = val;
        //includes keybegin but excludes keyend
            m_map[keyEnd] = m_valBegin;
        }

	}

	V const& operator[]( K const& key ) const
	{
		auto it=m_map.upper_bound(key);
		if(it==m_map.begin()) 
		{
			return m_valBegin;
		} 
		else 
		{
			return (--it)->second;
		}
	}
};





void assign(K const& keyBegin, K const& keyEnd, V const& val) 
{
    // Check to ensure the value of keyBegin is not greater than keyEnd
    if (keyBegin >= keyEnd) {
        return;
    }

    auto itrStart = m_map.lower_bound(keyBegin);
    auto itrEnd = m_map.lower_bound(keyEnd);

    if (itrStart == m_map.begin() && (itrStart == m_map.end() || itrStart->first > keyBegin)) {
        if (val != m_valBegin) {
            // set m_valBegin to be equal to val since we have noted it wasn't similar
            m_valBegin = val;
        }
    }
    else {
        --itrStart;
    }

    // erase interval
    m_map.erase(itrStart, itrEnd);

    if (val != m_valBegin) {
        m_map[keyBegin] = val;
        // includes keybegin but excludes keyend
        m_map[keyEnd] = m_valBegin;
    }
}

