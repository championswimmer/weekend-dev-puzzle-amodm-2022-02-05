#include <iostream>
#include <string>
#include <time.h>

#define MAX_DATA_SIZE 15*1024*1024

void die(const char *err)
{
    std::cerr << "error: " << err << std::endl;
    std::cerr << "usage: <progname> count <lessthan> <times>" << std::endl;
    exit(1);
}

int read_dataset(int *data)
{
    int count = 0;
    for (std::string line; std::getline(std::cin, line);) {
        data[count++] = atoi(line.c_str());
        if (count == MAX_DATA_SIZE) {
            die("received more than manageable data size");
        }
    }
    return count;
}

int count_times(int *data, int data_size, int threshold, int times)
{
    int count=0;
    for (int n=0; n<times; n++) {
        for (int i=0; i<data_size; i++) {
            if (data[i] < threshold) {
                count++;
            }
        }
    }
    return count;
}

int main(int argc, char *argv[])
{
    if (argc != 4) {
        die("incorrect arguments");
    }
    std::string cmd = argv[1];
    if (cmd != "count") {
        die("command needs to be 'count'");
    }
    int threshold = atoi(argv[2]);
    int times = atoi(argv[3]);

    int *data = new int[MAX_DATA_SIZE];

    // read data from stdin
    int data_size = read_dataset(data);

    // warm up
    count_times(data, data_size, threshold, 10);

    // start timer & measure
    clock_t start = clock();
    int count = count_times(data, data_size, threshold, times);
    clock_t delta = clock() - start;
    std::cout << "Number of matching entries = " << count << ". Time taken = " << ((1.0*delta)/CLOCKS_PER_SEC) << "s" << std::endl;

    return 0;
}
