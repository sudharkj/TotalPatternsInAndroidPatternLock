#ifndef PATTERN_H
#define PATTERN_H

class pattern
{
public:
    int m_length;//!< Member variable "m_length"
    long long m_adj[nodes][nodes];//!< Member variable "m_adj"
    long long m_freq[nodes][nodes][nodes];//!< Member variable "m_freq"
    /** Default constructor */
    pattern();
    /** Constructor with parameter
     *  \param a Initial 2D array
     */
    pattern(long long a[][nodes], int length);
    /** Computes the resultant pattern on combining two patterns
     * \param other Other pattern to combine with the current one
     */
    void combine(const pattern& other);
    /** Computes and returns total number of patterns of
     *  length m_length possible for android lock
     * \return total number of patterns
     */
    long long count();

protected:

private:

};

#endif // PATTERN_H
