const char* TextureShader_vert = STRINGIFY(
                                           
attribute vec4 vPosition;

uniform mat4 modelView;
uniform mat4 projection;

// 光照参数
//uniform mat3 normalMatrix;
//uniform vec3 vLightPosition;
//uniform vec4 vAmbientMaterial;
//uniform vec4 vSpecularMaterial;
//uniform float shininess;
//attribute vec3 vNormal;
//attribute vec4 vDiffuseMaterial;
//varying vec4 vDestinationColor;

void main(void)
{
    gl_Position = projection * modelView * vPosition;
    
//    vec3 N = normalMatrix * normalize(vNormal);
//    vec3 L = normalize(vLightPosition);
//    vec3 E = vec3(0, 0, 1);
//    vec3 H = normalize(L + E);
//    
//    float df = max(0.0, dot(N, L));
//    float sf = max(0.0, dot(N, H));
//    sf = pow(sf, shininess);
    
    // df 漫反射因子：它是光线与顶点法线向量的点积，几何意义就是光线 L 与法线 N 之间夹角的 cos 值；
    // sf 镜面反射因子：它是视线 E 与光线 L 形成的夹角的平分线 H 与顶点法线向量的点积（几何意义就是平分线 H 与顶点法线 N 之间夹角的 cos 值），再 shininess 次方；
//    vDestinationColor = vAmbientMaterial + df * vDiffuseMaterial + sf * vSpecularMaterial;
}
                                           );
