#include <iostream>
#include <memory>
using namespace std;
struct MemoryBlock {
    int size;

    MemoryBlock(int s) : size(s) {
        cout << "Bloc de memoire alloue de " << size << " unites." << endl;
    };
    ~MemoryBlock() {
        cout << "Liberation de la memoire"<< endl;
    }
};
unique_ptr<MemoryBlock> merge(unique_ptr<MemoryBlock> a, unique_ptr<MemoryBlock> b) {
    int newSize = a->size + b->size;
    auto mergedBlock = make_unique<MemoryBlock>(newSize);
    cout << "Fusion des deux blocs : " << mergedBlock->size << " unites." << endl;
    return mergedBlock;
}
int main() {
    unique_ptr<MemoryBlock> block1 = make_unique<MemoryBlock>(100);
    unique_ptr<MemoryBlock> block2 = make_unique<MemoryBlock>(200);
    unique_ptr<MemoryBlock> mergedBlock = merge(move(block1), move(block2));
    return 0;
}