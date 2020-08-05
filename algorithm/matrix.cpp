#ifndef MATRIX_H
#define MATRIX_H

#include <vector>
using namespace std;

template <typename Object>
class Matrix
{
    public:
        Matrix(int rows, int cols): array(rows)
        {
            for(auto &thisRow : array)
                thisRow.resize(cols);
        }

        Matrix(vector<vector<Object>> v): array{ v }
            {}
        Matrix(vector<vector<Object>> &&v): array{move(v)}
            {}

        const vector<Object> &operator[](int row) const
            {return array[row];}
        vector<Object> &operator[](int row)
            {return array[row];}

        int numrows() const {return array.size();}
        int numcols() const {return numrows()? array[0].size : 0;}
    
    private:
        vector<vector<Object>> array;
};
#endif