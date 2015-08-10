

cbuffer cbPerObject
{
	float4x4 WVP;
};
struct VOut
{
	float4 position : SV_POSITION;
	float4 color : COLOR;
};

VOut VShader(float4 inPos : POSITION, float4 inColor : COLOR)
{
	VOut output;

	output.position = mul(inPos, WVP);
	output.color = inColor;

	return output;
}


float4 PShader(float4 position : SV_POSITION, float4 color : COLOR) : SV_TARGET
{
	return color;
}