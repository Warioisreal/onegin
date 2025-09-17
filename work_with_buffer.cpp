void BufferToText(struct OneginStr** text, const char* buffer) {
    char* ptr1 = buffer;
    char* ptr2 = strchr(ptr1, '\n');

    size_t pos = 0;
    while (ptr2 != nullptr) {
        if (ptr2 - ptr1 > 1) {
            *text[pos] = {ptr1, (size_t)(ptr2 - ptr1)};
            pos++;
        }
        *ptr2 = '\0';
        ptr1 = ptr2 + 1;
        ptr2 = strchr(ptr1, '\n');
    }
}
