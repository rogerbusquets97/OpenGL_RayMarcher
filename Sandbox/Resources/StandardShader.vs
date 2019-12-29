#version 440 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aTexCoords;

uniform mat4 viewMatrix;
uniform mat4 projectionMatrix;

out Data
{
	vec2 FragCoords;
} vs_out;

void main()
{
	vs_out.FragCoords = aTexCoords;
	gl_Position = projectionMatrix * viewMatrix * vec4(aPos, 1.0f);
	//gl_Position = vec4(aPos, 1.0);
}