# ifdef COMPILING_VERTEX
layout(location = 0) in vec3 aPos;
layout(location = 1) in vec2 aTexCoords;

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
}
#endif

# ifdef COMPILING_FRAGMENT
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
	FragColor.rgb = pow(FragColor.rgb, vec3(1.0 / 2.4));
}
#endif