void Swap(void* ptr1, void* ptr2) {
    struct OneginStr* p1 = (struct OneginStr*)(ptr1);
    struct OneginStr* p2 = (struct OneginStr*)(ptr2);
    struct OneginStr buf_ptr;
    buf_ptr = *p1;
    *p1 = *p2;
    *p2 = buf_ptr;
}
