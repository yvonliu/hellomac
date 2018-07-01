#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
#include <random>
#include <queue>

using array = std::vector<int>;
void print_array(array::iterator begin, array::iterator end)
{
    using namespace std;
    for(auto i = begin; i < end; ++i) cout << *i << " ";
    cout << endl;
}

namespace my_quicksort 
{
    array::iterator partition(array::iterator begin, array::iterator end)
    {
        using namespace std;
        uniform_int_distribution<int> dist(0, static_cast<int>(end-begin) - 1);
        default_random_engine generator(time(0));
        int p_offset = dist(generator);
        std::swap( *(end-1), *(begin + p_offset));

        auto pivot = (end-1);
        auto front = begin;
        auto next_pivot = begin;

        while (front < pivot)
        {
            if (*front < *pivot)
            {
                std::swap(*front, *next_pivot);
                cout << "#";
                next_pivot++;
            }
            front++;
        }
        std::swap(*next_pivot, *pivot);
        return next_pivot;
    }
    void quickSort(array::iterator begin, array::iterator end)
    {
        if (begin < end)
        {
            array::iterator pivot = partition(begin, end);
            quickSort(begin, pivot);
            quickSort(pivot + 1, end);
        }
    }

    void testQuickSort()
    {
        array a = {1,2,3,4,5,6,7,8,9};
        array b = {9,8,7,6,5,4,3,2,1};
        array c = {6,3,7,1,4,8,9,2,5};
        array x = {1103, 892, 1109, 8963, 8850, 1690, 1497, 7973, 5607, 8300, 9089, 6306, 9286, 7338, 3211, 519, 3061, 1682, 3778, 6222, 5716, 2789, 3963, 1258, 6798, 8967, 3261, 9861, 133, 6446, 4643, 2076, 9565, 9049, 6392, 873, 6143, 2396, 512, 6255, 8542, 7811, 1990, 7492, 6734, 5904, 8634, 8467, 3285, 2804, 6463, 3264, 787, 64, 5603, 6157, 7314, 8188, 5143, 7613, 8371, 797, 1091, 3405, 6981, 9618, 6819, 6531, 6142, 5485, 4673, 6916, 294, 6058, 6103, 7797, 8553, 5091, 3140, 3406, 6930, 7093, 9661, 1236, 2584, 19, 2720, 1654, 8579, 1374, 6117, 5759, 9438, 3656, 4357, 7631, 272, 4404, 8552};
        quickSort(a.begin(), a.end());
        print_array(a.begin(), a.end());
        quickSort(b.begin(), b.end());
        print_array(b.begin(), b.end());
        quickSort(c.begin(), c.end());
        print_array(c.begin(), c.end());
        quickSort(x.begin(), x.end());
        print_array(x.begin(), x.end());
    }
}

namespace my_mergesort
{

    void mergeHeap(array::iterator begin, array::iterator mid, array::iterator end)
    {
        array left_buffer(begin, mid); left_buffer.push_back(INT_MAX);
        array right_buffer(mid, end); right_buffer.push_back(INT_MAX);
        auto left = left_buffer.begin();
        auto right = right_buffer.begin();

        for (auto i = begin; i < end; i++)
        {
            if (*left < *right)
            {
                *i = *left; ++left;
            }
            else
            {
                *i = *right; ++right;
            }
        }
    }
    void mergeSort(array::iterator begin, array::iterator end)
    {
        if (begin < end-1)
        {
            array::iterator mid = begin + static_cast<int>(end-begin) / 2;
            mergeSort(begin, mid);
            mergeSort(mid, end);
            mergeHeap(begin, mid, end);
        }
    }
    void testMergeSort()
    {
        array a = {1,2,3,4,5,6,7,8,9};
        array b = {9,8,7,6,5,4,3,2,1};
        array c = {6,3,7,1,4,8,9,2,5};
        array x = {1103, 892, 1109, 8963, 8850, 1690, 1497, 7973, 5607, 8300, 9089, 6306, 9286, 7338, 3211, 519, 3061, 1682, 3778, 6222, 5716, 2789, 3963, 1258, 6798, 8967, 3261, 9861, 133, 6446, 4643, 2076, 9565, 9049, 6392, 873, 6143, 2396, 512, 6255, 8542, 7811, 1990, 7492, 6734, 5904, 8634, 8467, 3285, 2804, 6463, 3264, 787, 64, 5603, 6157, 7314, 8188, 5143, 7613, 8371, 797, 1091, 3405, 6981, 9618, 6819, 6531, 6142, 5485, 4673, 6916, 294, 6058, 6103, 7797, 8553, 5091, 3140, 3406, 6930, 7093, 9661, 1236, 2584, 19, 2720, 1654, 8579, 1374, 6117, 5759, 9438, 3656, 4357, 7631, 272, 4404, 8552};
        mergeSort(a.begin(), a.end());
        print_array(a.begin(), a.end());
        mergeSort(b.begin(), b.end());
        print_array(b.begin(), b.end());
        mergeSort(c.begin(), c.end());
        print_array(c.begin(), c.end());
        mergeSort(x.begin(), x.end());
        print_array(x.begin(), x.end());
    }
}

namespace my_heapsort
{
    void maxHeapify(array::iterator base, int index, int size)
    {
        int left = index * 2;
        int right = index * 2 + 1;
        int max = index;

        if (left <= size && *(base+max) < *(base+left))
        {
            max = left; 
        }
        if (right <= size && *(base+max) < *(base+right))
        {
            max = right; 
        }
        if (max != index)
        {
            std::swap(*(base+index), *(base+max));
            maxHeapify(base, max, size);
        }
    }
    void buildHeap(array::iterator begin, array::iterator end)
    {
        array::iterator base = begin - 1;
        int size = end - begin;
        
        for (int i = size/2; i >= 1; --i)
        {
            maxHeapify(base, i, size);
        }
    }
    void heapSort(array::iterator begin, array::iterator end)
    {
        buildHeap(begin, end);
        array::iterator base = begin - 1;
        int size = end - begin;
        for (int i = 1; i < size; ++i)
        {
            std::swap(*begin, *(end - i));
            maxHeapify(base, 1, size - i);
        }
    }
    void heapSortPQueue(array::iterator begin, array::iterator end)
    {
        std::priority_queue<int, array, std::greater<int>> pq(begin, end);
        for (auto it = begin; it < end; ++it)
        {
            *it = pq.top();
            pq.pop();
        }
    }
    void testHeapSort()
    {
        array x = {1103, 892, 1109, 8963, 8850, 1690, 1497, 7973, 5607, 8300, 9089, 6306, 9286, 7338, 3211, 519, 3061, 1682, 3778, 6222, 5716, 2789, 3963, 1258, 6798, 8967, 3261, 9861, 133, 6446, 4643, 2076, 9565, 9049, 6392, 873, 6143, 2396, 512, 6255, 8542, 7811, 1990, 7492, 6734, 5904, 8634, 8467, 3285, 2804, 6463, 3264, 787, 64, 5603, 6157, 7314, 8188, 5143, 7613, 8371, 797, 1091, 3405, 6981, 9618, 6819, 6531, 6142, 5485, 4673, 6916, 294, 6058, 6103, 7797, 8553, 5091, 3140, 3406, 6930, 7093, 9661, 1236, 2584, 19, 2720, 1654, 8579, 1374, 6117, 5759, 9438, 3656, 4357, 7631, 272, 4404, 8552};
        array y = {1103, 892, 1109, 8963, 8850, 1690, 1497, 7973, 5607, 8300, 9089, 6306, 9286, 7338, 3211, 519, 3061, 1682, 3778, 6222, 5716, 2789, 3963, 1258, 6798, 8967, 3261, 9861, 133, 6446, 4643, 2076, 9565, 9049, 6392, 873, 6143, 2396, 512, 6255, 8542, 7811, 1990, 7492, 6734, 5904, 8634, 8467, 3285, 2804, 6463, 3264, 787, 64, 5603, 6157, 7314, 8188, 5143, 7613, 8371, 797, 1091, 3405, 6981, 9618, 6819, 6531, 6142, 5485, 4673, 6916, 294, 6058, 6103, 7797, 8553, 5091, 3140, 3406, 6930, 7093, 9661, 1236, 2584, 19, 2720, 1654, 8579, 1374, 6117, 5759, 9438, 3656, 4357, 7631, 272, 4404, 8552};
        heapSort(x.begin(), x.end());
        print_array(x.begin(), x.end());
        heapSortPQueue(y.begin(), y.end());
        print_array(y.begin(), y.end());
    }
}
