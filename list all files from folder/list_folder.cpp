#include <windows.h>
#include <iostream>
#include <string>

using namespace std;

int main() {

	int n_files = 0;

	wchar_t* file = L"D://Course//Computer Vision//*.txt";
	WIN32_FIND_DATA FindFileData;

	HANDLE hFind;
	hFind = FindFirstFile(file, &FindFileData);

	if (hFind != INVALID_HANDLE_VALUE) {

		do
		{
			wcout << FindFileData.cFileName << "\n"; //因為取得的檔案名稱是wchar型態, 所以無法用cout直接輸出

			wstring ws(FindFileData.cFileName); //利用wstring 將wchar型態的檔案名稱轉成string型態
			string findFileData_str(ws.begin(), ws.end());

			//cout << findFileData_str << endl;
			n_files++;
		} while ( FindNextFile(hFind, &FindFileData) == TRUE);
	}

	cout << endl << "Number of files: " << n_files << endl;

	system("pause");
	return 0;
}
