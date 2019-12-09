#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoords;

out VS_OUT
{
	vec2 FragCoords;
} vs_out;

void main()
{
	vs_out.FragCoords = aTexCoords;
	gl_position = vec4(aPos, 1.0);
}