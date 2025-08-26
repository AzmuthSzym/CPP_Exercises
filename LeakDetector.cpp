
#include <iostream>
#include <vector>

struct AllocationInfo {
    void* ptr;
    size_t size;
    bool is_active;  // or whatever you want to call the status
};

class LeakDetector {
private:
    std::vector<AllocationInfo> allocations;

public:
    void* operator new(size_t size);
    void operator delete(void* ptr);

    void* allocate(size_t size)
    {
        void* last_ptr = malloc(size);
        std::cout << "Allocated " << size << " bytes at " << last_ptr << std::endl;
        allocations.push_back(AllocationInfo{ last_ptr, size, true });
        return last_ptr;
    }
    void deallocate(void* ptr)
    {
        for (AllocationInfo& allo : allocations)
        {
            if (allo.ptr == ptr)
            {
                allo.is_active = false;
                //free(ptr);
                std::cout << "Freed " << allo.size << " bytes at " << allo.ptr << std::endl;
            }
        }
    }
    void print_layout()
    {
        for (AllocationInfo& allo : allocations)
        {
            if (allo.is_active)
            {
                std::cout << "USED:[" << allo.size << "]" << std::endl;
            }
            else
            {
                std::cout << "FREE:[" << allo.size << "]" << std::endl;
            }
        }
    }
};

int main()
{
    HeapVisualizer heap;
    void* p1 = heap.allocate(100);
    void* p2 = heap.allocate(200);
    void* p3 = heap.allocate(50);
    heap.deallocate(p2);
    heap.print_layout();
    return 0;
}
