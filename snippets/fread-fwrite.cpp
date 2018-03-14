// 其中返回值是成功读取、写出的 nmemb 数。这一点有助于查错。
size_t fread(        void *ptr, size_t size, size_t nmemb, FILE *stream );
size_t fwrite( const void *ptr, size_t size, size_t nmemb, FILE *stream );
