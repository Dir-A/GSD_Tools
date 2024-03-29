#include <iostream>

#include <Rut/RxCmd.h>
#include <GSD/GSP_Editor.h>


static void UserMain(int argc, wchar_t* argv[])
{
	Rut::RxCmd::Arg arg;
	arg.AddCmd(L"-gsp", L"gsp file path");
	arg.AddCmd(L"-folder", L"files folder path");
	arg.AddCmd(L"-mode", L"mode: [extract] [pack]");
	arg.AddExample(L"-mode extract -gsp data.gsp -folder data/");
	arg.AddExample(L"-mode pack -folder data/ -gsp data.gsp.new");
	if (arg.Load(argc, argv) == false) { return; }

	if (arg[L"-mode"] == L"extract")
	{
		GSD::GSP::Extract(arg[L"-gsp"], arg[L"-folder"]);
	}
	else if (arg[L"-mode"] == L"pack")
	{
		GSD::GSP::Pack(arg[L"-folder"], arg[L"-gsp"]);
	}
	else
	{
		throw std::runtime_error("Command Error!");
	}

}

int wmain(int argc, wchar_t* argv[])
{
	try
	{
		::UserMain(argc, argv);
	}
	catch (const std::exception& err)
	{
		std::cerr << err.what() << std::endl;
	}
}