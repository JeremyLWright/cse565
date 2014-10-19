int main(int argc, char *argv[])
{
    int i;
    //Lots other code
    //Removed for clarity
    while(i < totalThreads) {
        start_thread(func1);
        ++i;
    }
    //...
}
        

