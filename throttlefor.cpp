#include <windows.h>
#include <PowrProf.h>
#include <winnt.h>

#include <vector>
#include <iterator>
#include <string>
#include <sstream>

#pragma comment(lib, "PowrProf.lib")

using namespace std;

void setMaxCpuState(int percentage) {
	GUID *guid;	
	PowerGetActiveScheme(NULL, &guid);
	DWORD v = percentage;
	PowerWriteACValueIndex(NULL, guid, &GUID_PROCESSOR_SETTINGS_SUBGROUP, &GUID_PROCESSOR_THROTTLE_MAXIMUM, v);
	PowerWriteDCValueIndex(NULL, guid, &GUID_PROCESSOR_SETTINGS_SUBGROUP, &GUID_PROCESSOR_THROTTLE_MAXIMUM, v);
	PowerSetActiveScheme(NULL, guid);
}

int WINAPI WinMain(HINSTANCE inst, HINSTANCE prev, LPSTR cmd, int show)
{
	vector<string> args{ istream_iterator<string>{istringstream(cmd)}, istream_iterator<string>{} };


	// defaults
	if (args.size() == 0) {
		args.push_back("40"); // %
	}
	if (args.size() < 2) {
		args.push_back("10"); // seconds
	}


	if (args.size() < 2) {
		MessageBox(
			NULL,
			(LPCWSTR)
			L"Usage:\nthrottlefor.exe MAX_CPU SECONDS"
			L"    \n"
			,
			(LPCWSTR)L"throttle-for",
			MB_ICONWARNING 
		);
		return 1;
	}

	int maxState = std::stoi(args[0]);
	int seconds = std::stoi(args[1]);

	setMaxCpuState(maxState);
	Sleep(seconds * 1000);
	setMaxCpuState(100);
}
