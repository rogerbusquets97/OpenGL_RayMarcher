#version 330 core

in FS_IN
{
	vec2 TexCoords;
} fs_in;

out vec4 FragColor;

void main()
{
	FragColor = vec4(1.0, 0.0, 0.0, 1.0);
}