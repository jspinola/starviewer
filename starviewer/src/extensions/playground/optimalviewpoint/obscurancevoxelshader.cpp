#include "obscurancevoxelshader.h"


namespace udg {


ObscuranceVoxelShader::ObscuranceVoxelShader()
    : VoxelShader()
{
    m_obscurance = 0;
    m_factor = 1.0;
    m_lowFilter = 0.0; m_highFilter = 1.0;
}


ObscuranceVoxelShader::~ObscuranceVoxelShader()
{
}


void ObscuranceVoxelShader::setObscurance( const double *obscurance )
{
    m_obscurance = obscurance;
}


void ObscuranceVoxelShader::setFactor( double factor )
{
    m_factor = factor;
}


void ObscuranceVoxelShader::setFilters( double low, double high )
{
    m_lowFilter = low; m_highFilter = high;
}


HdrColor ObscuranceVoxelShader::shade( int offset, const Vector3 &direction, const HdrColor &baseColor ) const
{
    Q_UNUSED( direction );

    Q_CHECK_PTR( m_data );
    Q_CHECK_PTR( m_obscurance );

    if ( baseColor.isTransparent() || baseColor.isBlack() ) return baseColor;

    double obscurance = m_obscurance[offset];
    if ( obscurance < m_lowFilter ) obscurance = 0.0;
    else if ( obscurance > m_highFilter ) obscurance = 1.0;
    obscurance *= m_factor;

    HdrColor shaded = baseColor;
    shaded.multiplyColorBy( obscurance );

    return shaded;
}


QString ObscuranceVoxelShader::toString() const
{
    return "ObscuranceVoxelShader";
}


}
