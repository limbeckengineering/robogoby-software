#pragma once

#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>
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
	void RenderFrame(void);

private:
	HRESULT CompileShaderFromFile(WCHAR* szFileName,
		LPCSTR szEntryPoint, LPCSTR szShaderModel, ID3DBlob** ppBlobOut);
	void InitGraphics(void);    // creates the shape to render
	void InitPipeline(void);    // loads and prepares the shaders

	int width = 640;
	int height = 480;

	IDXGISwapChain *swapchain;					// the pointer to the swap chain interface
	ID3D11Device *dev;							// the pointer to our Direct3D device interface
	ID3D11DeviceContext *devcon;				// the pointer to our Direct3D device context
	ID3D11RenderTargetView *backbuffer;			// pointer to the back buffer
	ID3D11InputLayout *pVertexLayout;           // the pointer to the input layout
	ID3D11VertexShader *pVS;					// the pointer to the vertex shader
	ID3D11PixelShader *pPS;						// the pointer to the pixel shader
	ID3D11PixelShader *pPSSolid;
	ID3D11Buffer *pVBuffer;						// the pointer to the cube vertex buffer
	ID3D11Buffer *pIBuffer;						//pointer to the Index Buffer
	ID3D11Buffer *pConstantBuffer;		
	ID3D11DepthStencilView* depthStencilView;
	ID3D11Texture2D* depthStencilBuffer;

	//camera
	XMMATRIX World;
	XMMATRIX View;
	XMMATRIX Projection;

	// a struct to define a single vertex
	struct VERTEX
	{
		XMFLOAT3 Pos;
		XMFLOAT3 Normal;
	};


	struct ConstantBuffer
	{
		XMMATRIX mWorld;
		XMMATRIX mView;
		XMMATRIX mProjection;
		XMFLOAT4 vLightDir;
		XMFLOAT4 vLightColor;
		XMFLOAT4 vOutputColor;
	};

};

