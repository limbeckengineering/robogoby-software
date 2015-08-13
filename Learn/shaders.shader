struct Light
{
	float3 dir;
	float4 ambient;
	float4 diffuse;
};

cbuffer cbPerFrame
{
	Light light;
};

cbuffer cbPerObject
{
	float4x4 WVP;
	float4x4 World;
};

struct VOut
{
	float4 position : SV_POSITION;
	float4 color : COLOR;
	float3 normal : NORMAL;
};

VOut VShader(float4 inPos : POSITION, float4 inColor : COLOR, float3 normal : NORMAL)
{
	VOut output;

	output.position = mul(inPos, WVP);
	output.color = inColor;
	output.normal = mul(normal, World);

	return output;
}

float4 PShader(VOut input) : SV_TARGET
{

	return float4 input.color;

}