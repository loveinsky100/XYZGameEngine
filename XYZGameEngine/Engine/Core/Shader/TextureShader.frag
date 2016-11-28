const char* TextureShader_frag = STRINGIFY(

precision mediump float; //设置工作精度

varying vec2 vTexture;

uniform sampler2D sTexture;

void main()
{
    gl_FragColor = texture2D(sTexture, vTexture);
}
                                           );
