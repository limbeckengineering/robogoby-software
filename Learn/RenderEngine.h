#pragma once

#include <d3d11.h>
#include <d3dcompiler.h>
#include <DirectXMath.h>

//#include <d3d10.h>
//might need to include these but will try without (if not instructions for include found on Stack Overflow)

// include the Direct3D Library file
#pragma comment (lib, "d3d11.lib")
#pragma comment (lib, "d3dcompiler.lib")
//#pragma comment (lib, "d3dx11.lib")
//#pragma comment (lib, "d3dx10.lib")


class RenderEngine
{
public:
	RenderEngine(HWND hWnd);
	virtual ~RenderEngine();
	void RenderFrame(void);
	void InitGraphics(void);    // creates the shape to render
	void InitPipeline(void);    // loads and prepares the shaders
	void updateScene(void);

private:
	int width = 400;
	int height = 400;

	IDXGISwapChain *swapchain;				// the pointer to the swap chain interface
	ID3D11Device *dev;						// the pointer to our Direct3D device interface
	ID3D11DeviceContext *devcon;			// the pointer to our Direct3D device context
	ID3D11RenderTargetView *backbuffer;		// pointer to the back buffer
	ID3D11InputLayout *pLayout;            // the pointer to the input layout
	ID3D11VertexShader *pVS;               // the pointer to the vertex shader
	ID3D11PixelShader *pPS;                // the pointer to the pixel shader
	ID3D11Buffer *pVBuffer;                // the pointer to the square vertex buffer
	ID3D11Buffer *pIBuffer;					//pointer to the Index Buffer
	ID3D11DepthStencilView* depthStencilView;
	ID3D11Texture2D* depthStencilBuffer;
	ID3D11Buffer* cbPerObjectBuffer;

	DirectX::XMMATRIX WVP;
	DirectX::XMMATRIX World;
	DirectX::XMMATRIX camView;
	DirectX::XMMATRIX camProjection;

	DirectX::XMVECTOR camPosition;
	DirectX::XMVECTOR camTarget;
	DirectX::XMVECTOR camUp;

	DirectX::XMMATRIX cube1World;
	DirectX::XMMATRIX cube2World;

	DirectX::XMMATRIX Rotation;
	DirectX::XMMATRIX Scale;
	DirectX::XMMATRIX Translation;
	float rotation = 0.01f;

	// a struct to define a single vertex
	struct VERTEX { FLOAT X, Y, Z; float color[4]; };

	//Create effects constant buffer's structure//
	struct cbPerObject
	{
		DirectX::XMMATRIX  WVP;
	};

	cbPerObject cbPerObj;
};

