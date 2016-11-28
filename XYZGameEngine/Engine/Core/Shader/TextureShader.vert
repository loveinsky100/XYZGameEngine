const char* TextureShader_vert = STRINGIFY(
attribute vec4 vPosition;
attribute vec2 vTextureCood;

varying vec2 vTexture;

void main(void)
{
    gl_Position = vPosition;
    vTexture = vTextureCood;
}
                                           );
