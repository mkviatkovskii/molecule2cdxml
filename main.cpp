#include <iostream>

#include <base_cpp/output.h>
#include <base_cpp/scanner.h>
#include <molecule/molecule.h>
#include <molecule/molecule_auto_loader.h>
#include <molecule/molecule_cdxml_saver.h>

using namespace indigo;

#ifndef EX_USAGE
#define EX_USAGE 64
#endif

std::string molecule2cdxml(const std::string& input)
{
    BufferScanner scanner(input.c_str());
    MoleculeAutoLoader moleculeLoader(scanner);
    Molecule molecule;
    moleculeLoader.loadMolecule(molecule);
    Array<char> array;
    ArrayOutput output(array);
    MoleculeCdxmlSaver cdxmlSaver(output);
    cdxmlSaver.saveMolecule(molecule);
    return array.ptr();
}

int main(int argc, char *argv[])
{
    if (argc < 2)
    {
        std::cout << "usage: molecule2cdxml <SMILES string>\n";
        return EX_USAGE;
    }
    try
    {
        std::cout << molecule2cdxml(argv[1]);
    }
    catch (const Exception &e)
    {
        std::cout << "Fatal error: " << e.what() << '\n';
        return 1;
    }
}
