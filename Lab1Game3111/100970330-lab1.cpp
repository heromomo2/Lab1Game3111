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
#include <DirectXPackedVector.h>
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
		os << XMVectorGetX(m.r[i]) << "\t";
		os << XMVectorGetY(m.r[i]) << "\t";
		os << XMVectorGetZ(m.r[i]) << "\t";
		os << XMVectorGetW(m.r[i]);
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
	XMMATRIX InverseMatrix; /*(
		0.0f, 0.0f, 0.0f, 0.0f,

		0.0f, 0.0f, 0.0f, 0.0f,

		0.0f, 0.0f, 0.0f, 0.0f,

		0.0f, 0.0f, 0.0f, 0.0f

	);*/
	// 4X4 MATRIX
	 XMMATRIX A
	(  1.0f , 0.0f, 0.0f, 0.0f,

		0.0f, 2.0f, 0.0f, 0.0f,

		0.0f, 0.0f, 4.0f, 0.0f,

		1.0f, 2.0f, 3.0f , 1.0f

	);


	 
	 XMVECTOR  det = XMMatrixDeterminant(A);

	 if (XMVectorGetX(det)!= 0 ) 
	 {
		 InverseMatrix = XMMatrixInverse(&det, A);

		 cout << "A = " << endl << A << endl; 
		 cout << "det =  determinant(A) = " << endl << A << endl;
		 cout << "InverseMatrix = " << endl << InverseMatrix << endl;
	 }
	 else {
	 
		 cout << "Determinant was empty" << endl;
	 }


	 
//	 XMVECTOR det = XMMatrixDeterminant(A);

//	 XMMATRIX F = A * E;


	
	 int numblock; 
	 cin >> numblock;
	return 0;
}