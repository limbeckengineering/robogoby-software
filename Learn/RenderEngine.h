#pragma once

#include <vector>
#include <iostream>
#include <fstream>
#include <cstring>
#include <iterator>
#include <d3d11_1.h>
#include <d3dcompiler.h>
#include <directxmath.h>
#include <directxcolors.h>

// include the Direct3D Library file
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dcompiler.lib")

using namespace DirectX;

class RenderEngine
{
public:
	RenderEngine(HWND hWnd);
	virtual ~RenderEngine();
	void RenderFrame(float pitchAngle, float yawAngle);

private:
	HRESULT CompileShaderFromFile(WCHAR* szFileName,
		LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut);
	void InitGraphics(void);    // creates the shape to render
	void InitPipeline(void);    // loads and prepares the shaders
	void constructObjFromFile();

	int width = 400;
	int height = 400;

	bool flat = false;

	D3D_DRIVER_TYPE         g_driverType = D3D_DRIVER_TYPE_NULL;
	D3D_FEATURE_LEVEL       g_featureLevel = D3D_FEATURE_LEVEL_11_0;
	ID3D11Device*           g_pd3dDevice = nullptr;
	ID3D11Device1*          g_pd3dDevice1 = nullptr;
	ID3D11DeviceContext*    g_pImmediateContext = nullptr;
	ID3D11DeviceContext1*   g_pImmediateContext1 = nullptr;
	IDXGISwapChain*         g_pSwapChain = nullptr;
	IDXGISwapChain1*        g_pSwapChain1 = nullptr;
	ID3D11RenderTargetView* g_pRenderTargetView = nullptr;
	ID3D11Texture2D*        g_pDepthStencil = nullptr;
	ID3D11DepthStencilView* g_pDepthStencilView = nullptr;
	ID3D11VertexShader*     g_pVertexShader = nullptr;
	ID3D11VertexShader*     g_pVertexShaderFlat = nullptr;
	ID3D11PixelShader*      g_pPixelShader = nullptr;
	ID3D11InputLayout*      g_pVertexLayout = nullptr;
	ID3D11Buffer*           g_pVertexBuffer = nullptr;
	ID3D11Buffer*           g_pIndexBuffer = nullptr;
	ID3D11Buffer*           g_pConstantBuffer = nullptr;
	ID3D11RasterizerState*	g_pRasterizerState = nullptr;
	XMMATRIX                g_World;
	XMMATRIX                g_View;
	XMMATRIX                g_Projection;

	//--------------------------------------------------------------------------------------
	// Structures
	//--------------------------------------------------------------------------------------
	struct SimpleVertex
	{
		XMFLOAT3 Pos;
		XMFLOAT3 Normal;

		SimpleVertex() {
			Pos = {};
			Normal = {};
		};

		SimpleVertex(XMFLOAT3 pos) {
			Pos = pos;
			Normal = {};
		};

	};


	struct ConstantBuffer
	{
		XMMATRIX mWorld;
		XMMATRIX mView;
		XMMATRIX mProjection;
		XMFLOAT4 vLightDir;
		XMFLOAT4 vLightColor;
		XMFLOAT4 vOutputColor;
		int normalIndices[32] = { 0 };
		XMFLOAT3 faceNormals[7] = { XMFLOAT3(0, 0, 0) };
	};

	std::vector<XMFLOAT3> normal;
	std::vector<SimpleVertex> vertices;
	std::vector<WORD> indices;

	std::vector<XMFLOAT3> faceNormal;
	std::vector<int> faceNormalIndices;

};

