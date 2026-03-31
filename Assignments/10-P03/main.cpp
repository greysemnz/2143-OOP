#inclue <iostream>
#include <string>
#include <cstdlib>
#include <>







int main(int argc, char* argv[]) {
    Args args = Args::parse(argc, argv);

    Image img;
    img.load(args.input);

    Pipeline pipeline;
    // build pipeline from args — see design note below
    for (const std::string& op : args.order) {
        if (op == "grayscale") pipeline.add(new Grayscale());
        if (op == "brighten")  pipeline.add(new Brighten(args.brighten));
        if (op == "blur")      pipeline.add(new Blur());
        if (op == "flipH")     pipeline.add(new FlipH());
        if (op == "flipV")     pipeline.add(new FlipV());
        if (op == "rotate")    pipeline.add(new Rotate(args.rotate));
    }

    pipeline.printSteps();
    pipeline.run(img.pixels);
    img.save(args.output);

    return 0;
}