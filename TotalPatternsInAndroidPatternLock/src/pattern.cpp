#include "defines.h"
#include "pattern.h"

/** @brief constructor
  *
  * default constructor
  */
pattern::pattern()
{
    int i, j, k;
    m_length = 0;
    fora(i,nodes) fora(j,nodes) m_adj[i][j] = 0;
    fora(i,nodes) fora(j,nodes) fora(k,nodes) m_freq[i][j][k] = 0;
}

/** @brief constructor
  *
  * constructor with 2d array as param
  */
pattern::pattern(long long a[][nodes], int length)
{
    int i, j, k;
    m_length = length;
    fora(i,nodes) fora(j,nodes) fora(k,nodes) m_freq[i][j][k] = 0;
    fora(i,nodes) fora(j,nodes)
    {
        m_adj[i][j] = a[i][j];
        m_freq[i][j][i] = m_freq[i][j][j] = a[i][j];
    }
}

/** @brief combine
  *
  * Computes the resultant pattern on combining two patterns
  */
void pattern::combine(const pattern& other)
{
    pattern buffer;
    int i, j, k;
    long long temp;
    fora(i,nodes)
    {
        fora(j,nodes)
        {
            buffer.m_adj[i][j] = 0;
            fora(k,nodes)
            {
                temp = (m_adj[i][k]-m_freq[i][k][j])*(other.m_adj[k][j]-other.m_freq[k][j][i]);
                buffer.m_adj[i][j] += temp;
                buffer.m_freq[i][j][i] += temp;
                buffer.m_freq[i][j][k] += temp;
                buffer.m_freq[i][j][j] += temp;
            }
        }
    }

    fora(i,nodes) fora(j,nodes)
    {
        m_adj[i][j] = buffer.m_adj[i][j];
        fora(k,nodes) m_freq[i][j][k] = buffer.m_freq[i][j][k];
    }

    m_length = m_length + other.m_length;
}

/** @brief count
  *
  * total number of patterns
  */
long long pattern::count()
{
    long long count = 0;
    int i, j;
    fora(i,nodes) fora(j,nodes) count = count + m_adj[i][j];
    return count;
}
