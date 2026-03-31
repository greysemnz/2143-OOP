#include <fstream>
#include <iostream>
#include <string>

using namespace std;

class Args {
public:
    std::string input_file;
    std::string output_file;
    bool verbose = false;
    int rotate = 0;

    static Args parse(int argc, char* argv[]) {
        Args args;
        args.parse_impl(argc, argv);
        args.validate();
        return args;
    }

private:
    Args() = default;

    void parse_impl(int argc, char* argv[]) {
        // parse flags and values
    }

    void validate() {
        // check correctness
    }
};

int main (int argc, char** argv) {
    // cout << argc << endl;
    // cout << argv[0] << endl;

    for (int i = 0; i < argc; i++) {
        cout << i << ": " << argv[i] << endl;
    }

    if (argc < 2) {
        cout << "Error: need a filename!" << endl;
        cout << "Usage: ./args <filename>" << endl;
        exit (1);
    }

    if (string (argv[3]) == "--grayscale") {
        // do something
    }
    ifstream fin;
    fin.open ("input");


    int x;
    while (!fin.eof ()) {
        fin >> x;
        cout << x << " ";
    }
}