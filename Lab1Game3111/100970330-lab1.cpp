//***************************************************************************
// 100970330 - Lab 1.cpp by Mohamud Mohamed (C) 2017 All Rights Reserved.
//
// Lab 1 submission.
//
// Description:
// Click run to see the results.
//
//*****************************************************************************

#include <windows.h>
#include <DirectXMath.h>
#include <iostream>

using namespace std;
using namespace DirectX;
using namespace DirectX::PackedVector;

// Overload the "<<" opertor so that we can use cout  to
// output XMVECTOR And XMATRIX objects.
ostream& XM_CALLCONV operator << (ostream& os, FXMVECTOR v) 
{
	XMFLOAT4 dest;
	XMStoreFloat4(&dest, v);
	os << "(" << dest.x << "," << dest.y << ", " << dest.z << ", "<< dest.w << ")";
	return os;
}
ostream&  XM_CALLCONV operator << (ostream& os, FXMMATRIX m) 
{
	for (int i = 0; i < 4; ++i)
	{
		os << XMVectorGetsX(m.r[i]) << "\t";
		os << XMVectorGetsY(m.r[i]) << "\t";
		os << XMVectorGetsZ(m.r[i]) << "\t";
		os << XMVectorGetsW(m.r[i]);
		os << endl;
	}
	return os;
}

int main() 
{
	//checking for support  SSE2 (Pentium4, AMD K8, and above)
	if (!XMVerifyCPUSupport()) 
	{
		cout << "directx math is supported" << endl;
		return 0;
	}
	// 4X4 MATRIX
	 XMMATRIX A
	(  1.0f , 0.0f, 0.0f, 0.0f,

		0.1f, 0.0f, 0.0f, 0.0f,

		3.0f, 0.1f, 0.0f, 0.0f,

		0.0f, 0.0f, 2.0f , 0.0f

	);

	// XMMATRIX  B = XMMatrixIdentity();

	// XMMATRIX c = A*B;
	 
//	 XMMATRIX D = XMMatrixDeterminant(A);
	 
//	 XMVECTOR det = XMMatrixDeterminant(A);

//	 XMMATRIX F = A * E;


	/* cout << "A = " << endl <<  A << endl;
	 cout << "B = " << endl << B << endl;
	 cout << "C = A*B =  " << endl << C << endl;
	 cout << "D =  Transpose (A) = " << endl << D << endl;
	 cout << "det =  determinant(A) = " << endl << A << endl;
	 cout << "A = " << endl << A << endl;*/

	return 0;
}