#version 440 core

in Data
{
	vec2 FragCoords;
} fs_in;

out vec4 FragColor;
uniform sampler2D OutputTexture;

void main()
{	
	vec2 uv = fs_in.FragCoords;
	FragColor = texture(OutputTexture, fs_in.FragCoords);
	//GammaCorrection
    FragColor.rgb = pow(FragColor.rgb, vec3(1.0/2.4));
}