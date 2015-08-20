static int numOfVertsRenderedInFace = 0;

static int normalIndicesIndex = 0;

//--------------------------------------------------------------------------------------
// Constant Buffer Variables
//--------------------------------------------------------------------------------------
cbuffer ConstantBuffer : register(b0)
{
	matrix World;
	matrix View;
	matrix Projection;
	float4 vLightDir;
	float4 vLightColor;
	float4 vOutputColor;
	int normalIndices[32];
	float3 faceNormals[7];
}


//--------------------------------------------------------------------------------------
struct VS_INPUT
{
	float4 Pos : POSITION;
	float3 Norm : NORMAL;
};

struct PS_INPUT
{
	float4 Pos : SV_POSITION;
	float3 Norm : TEXCOORD0;
};


//--------------------------------------------------------------------------------------
// Vertex Shader
//--------------------------------------------------------------------------------------
PS_INPUT VS(VS_INPUT input)
{
	PS_INPUT output = (PS_INPUT)0;
	output.Pos = mul(input.Pos, World);
	output.Pos = mul(output.Pos, View);
	output.Pos = mul(output.Pos, Projection);
	output.Norm = mul(float4(input.Norm, 1), World).xyz;

	return output;
}

//--------------------------------------------------------------------------------------
// Vertex Shader for flat light
//--------------------------------------------------------------------------------------
PS_INPUT VSFlat(VS_INPUT input)
{
	if (numOfVertsRenderedInFace == 3) {
		numOfVertsRenderedInFace = 0;
		normalIndicesIndex++;
	}

	PS_INPUT output = (PS_INPUT)0;
	output.Pos = mul(input.Pos, World);
	output.Pos = mul(output.Pos, View);
	output.Pos = mul(output.Pos, Projection);
	output.Norm = mul(float4(faceNormals[normalIndices[normalIndicesIndex]], 1), World).xyz;

	numOfVertsRenderedInFace++;
	return output;
}



//--------------------------------------------------------------------------------------
// Pixel Shader
//--------------------------------------------------------------------------------------
float4 PS(PS_INPUT input) : SV_Target
{
	float4 finalColor = vOutputColor;

	finalColor += saturate(dot((float3)vLightDir,input.Norm) * vLightColor);

	finalColor.a = 1;
	return finalColor;
}


