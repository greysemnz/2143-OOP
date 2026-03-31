class Pipeline {
public:
    void add(Filter* f);
    void run(Grid& pixels);
    void printSteps() const;   // print ordered list: grayscale -> blur -> ...
private:
    std::vector<Filter*> filters;
};