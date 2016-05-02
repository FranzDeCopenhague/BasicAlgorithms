#include <iostream>
#include <vector>

void display(std::vector<int> & data)
{
    for (auto value : data) {
        std::cout << value;
        std::cout << ',';
    }
    std::cout << std::endl;
}

template<typename DATA_TYPE>
class Sorting
{
    typedef size_t SIZE_TYPE;

    static const SIZE_TYPE MERGE_SORT_MIN_SIZE = 4;    

protected:

    static void top_down_split_merge(DATA_TYPE* data, SIZE_TYPE iStart, SIZE_TYPE iEnd, DATA_TYPE* aux)
    {
        auto range_size = iEnd - iStart;

        // data[iEnd] is outside of data scope.
        if (range_size < 2) {
            return; // size 1 is sorted
        }
        if (range_size < MERGE_SORT_MIN_SIZE) {
            // With small array size apply a different approach
            insertion_sort(data, iStart, iEnd);
        }

        // split and recursion O(n log n)
        auto iMiddle = (iEnd + iStart) / 2; // Review later, discuss iStart + ((iEnd - iStart) / 2)
        top_down_split_merge(data, iStart, iMiddle, aux);
        top_down_split_merge(data, iMiddle, iEnd, aux);
        top_down_merge(data, iStart, iMiddle, iEnd, aux);
        top_down_copy(aux, iStart, iEnd, data);
    }

    static void top_down_merge(DATA_TYPE* data, SIZE_TYPE iStart, SIZE_TYPE iMiddle, SIZE_TYPE iEnd, DATA_TYPE* aux)
    {
        auto iLeft = iStart;
        auto iRight = iMiddle;

        for (auto k = iStart; k < iEnd; ++k) {
            if ((iLeft < iMiddle) && ((iRight >= iEnd) || data[iLeft] <= data[iRight])) {
                aux[k] = data[iLeft];
                ++iLeft;
            } else {
                aux[k] = data[iRight];
                ++iRight;
            }
        }
    }

    static void top_down_copy(DATA_TYPE* aux, SIZE_TYPE iStart, SIZE_TYPE iEnd, DATA_TYPE* data)
    {
        for (auto k = iStart; k < iEnd; ++k) {
            data[k] = aux[k];
        }
    }

public:
    // data range is [iStart, iEnd)
    static void insertion_sort(DATA_TYPE* data, SIZE_TYPE iStart, SIZE_TYPE iEnd)
    {
        for (auto i = iStart + 1; i < iEnd; ++i) {
            auto value = data[i];
            auto j = i;
            while ((j >= 0) && (value < data[j - 1])) {
                data[j] = data[j - 1];
                --j;
            }
            data[j] = value;
        }
    }

    // data range is [iStart, iEnd)
    static void merge_sort(DATA_TYPE* data, SIZE_TYPE iStart, SIZE_TYPE iEnd)
    {
        // Auxiliary array O(n) space
        std::vector<DATA_TYPE> aux_data(iEnd);

        top_down_split_merge(data, iStart, iEnd, aux_data.data());
    }

};

int main()
{
    std::vector<int> data = { 6, 5, 3, 1, 8, 7, 2, 4 };

    display(data);
    Sorting<int>::merge_sort(data.data(), 0, data.size());
    display(data);

    return 0;
}

