// Fragment shader
#version 330
#extension GL_ARB_explicit_attrib_location : require

uniform sampler2D u_texture;
uniform bool u_gammaCorrection;

in vec2 v_texcoord;
out vec4 frag_color;

void main()
{
    frag_color = texture(u_texture, v_texcoord);
    frag_color.rgb /= frag_color.a; // opacity
    if (u_gammaCorrection)
    {
        frag_color.rgb = (frag_color.rgb, vec3(1.0 / 2.2));
    }
}
