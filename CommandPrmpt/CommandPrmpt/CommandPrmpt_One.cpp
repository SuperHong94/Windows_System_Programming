/*
	���α׷� ����: ��� ������Ʈ�� ���
*/

#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <locale.h>
#include <Windows.h>

#define STR_LEN 256 
#define CMD_TOKEN_NUM 10

TCHAR ERROR_CMD[] = _T("'%s'��(��) ������ �� �ִ� ���α׷��� �ƴմϴ�.\n");

int CmdProcessing(void);
TCHAR* StrLower(TCHAR*);

int _tmain(int argc, TCHAR* argv[])
{
	//�ѱ� �Է��� ����
	_tsetlocale(LC_ALL, _T("korean"));

	DWORD isExit;
	while (1)
	{
		isExit = CmdProcessing();
		if (isExit == TRUE)
		{
			_fputts(_T("��ɾ� ó���� �����մϴ�. \n"), stdout);
			break;
		}
	}
	return 0;
}

TCHAR cmdString[STR_LEN];
TCHAR cmdTokenList[CMD_TOKEN_NUM][STR_LEN];
TCHAR seps[] = _T(" ,\t\n");

/*************************
* �Լ�: TCHAR int cmdProcessing(void)
* ���: ��ɾ �Է� �޾Ƽ� �ش� ��ɾ �����Ǿ� �ִ� ����� �����Ѵ�.
*		exit�� �ԷµǸ� TRUE�� ��ȯ�ϰ� �̴� ���α׷��� ����� �̾�����.
*
***************************/

int CmdProcessing(void)
{
	_fputts(_T("BEST command prompt>> "), stdout);
	_getts_s(cmdString);
	TCHAR* next_token = NULL;
	TCHAR* token = _tcstok_s(cmdString, seps,&next_token); //�̰� ���� �������ֱ⿡(���ۿ�����) _tcstok_s�� �ٲ�
	int tokenNum = 0;
	while (token != NULL)
	{
		_tcscpy_s(cmdTokenList[tokenNum++], StrLower(token));
		token = _tcstok_s(NULL, seps, & next_token);

	}
	if (!_tcscmp(cmdTokenList[0], _T("exit"))) return TRUE;
	else if (!_tcscmp(cmdTokenList[0], _T("�߰��Ǵ� ��ɾ� 1"))) {}
	else if (!_tcscmp(cmdTokenList[0], _T("�߰��Ǵ� ��ɾ� 2"))) {}
	else _tprintf(ERROR_CMD, cmdTokenList[0]);

	return 0;

}

/*************************
* �Լ�: TCHAR * StrLower(TCHAR* pStr)
* ���: ���ڿ��� ���� �����ϴ� ��� �빮�ڸ� �ҹ��ڷ� �����Ѵ�. ����� ���ڿ� �����͸� ��ȯ�Ѵ�.
***************************/

TCHAR* StrLower(TCHAR* pStr)
{
	TCHAR* ret = pStr;
	while (*pStr) {
		if (_istupper(*pStr))
			*pStr = _totlower(*pStr);
		pStr++;
	}
	return ret;
}