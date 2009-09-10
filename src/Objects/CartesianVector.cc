/**
 *  @file PandoraPFANew/src/Objects/CartesianVector.cc
 * 
 *  @brief Implementation of the cartesian vector class.
 * 
 *  $Log: $
 */

#include "Objects/CartesianVector.h"

#include <cmath>

namespace pandora
{

CartesianVector::CartesianVector(float x, float y, float z) :
    m_x(x),
    m_y(y),
    m_z(z)
{
}

//------------------------------------------------------------------------------------------------------------------------------------------

CartesianVector::CartesianVector(const CartesianSpacePoint &cartesianSpacePoint) :
    m_x(cartesianSpacePoint.GetX()),
    m_y(cartesianSpacePoint.GetY()),
    m_z(cartesianSpacePoint.GetZ())
{
}

//------------------------------------------------------------------------------------------------------------------------------------------

CartesianVector::CartesianVector(const CartesianSpacePoint &spacePoint1, const CartesianSpacePoint &spacePoint2) :
    m_x(spacePoint2.GetX() - spacePoint1.GetX()),
    m_y(spacePoint2.GetY() - spacePoint1.GetY()),
    m_z(spacePoint2.GetZ() - spacePoint1.GetZ())
{
}

//------------------------------------------------------------------------------------------------------------------------------------------

float CartesianVector::GetMagnitude() const
{
    return std::sqrt(this->GetMagnitudeSquared());
}

//------------------------------------------------------------------------------------------------------------------------------------------

float CartesianVector::GetMagnitudeSquared() const
{
    return ((m_x * m_x) + (m_y * m_y) + (m_z * m_z));
}

//------------------------------------------------------------------------------------------------------------------------------------------

float CartesianVector::GetDotProduct(const CartesianVector &rhs) const
{
    return ((m_x * rhs.GetX()) + (m_y * rhs.GetY()) + (m_z * rhs.GetZ()));
}

//------------------------------------------------------------------------------------------------------------------------------------------

CartesianVector CartesianVector::GetCrossProduct(const CartesianVector &rhs) const
{
    return CartesianVector( (m_y * rhs.GetZ()) - (rhs.GetY() * m_z),
                            (m_z * rhs.GetX()) - (rhs.GetZ() * m_x),
                            (m_x * rhs.GetY()) - (rhs.GetX() * m_y));
}

//------------------------------------------------------------------------------------------------------------------------------------------

float CartesianVector::GetOpeningAngle(const CartesianVector &rhs) const
{
    float magnitudesSquared = this->GetMagnitudeSquared() * rhs.GetMagnitudeSquared();

    if (magnitudesSquared <= 0)
    {
        return 0.;
    }
    else
    {
        float cosTheta = this->GetDotProduct(rhs) / std::sqrt(magnitudesSquared);

        if (cosTheta > 1.)
        {
            cosTheta = 1.;
        }
        else if (cosTheta < -1.)
        {
            cosTheta = -1.;
        }

        return acos(cosTheta);
    }
}

//------------------------------------------------------------------------------------------------------------------------------------------
//------------------------------------------------------------------------------------------------------------------------------------------

CartesianVector operator+(const CartesianVector &lhs, const CartesianVector &rhs)
{
    return CartesianVector(lhs.GetX() + rhs.GetX(), lhs.GetY() + rhs.GetY(), lhs.GetZ() + rhs.GetZ());
}

//------------------------------------------------------------------------------------------------------------------------------------------

CartesianVector operator-(const CartesianVector &lhs, const CartesianVector &rhs)
{
    return CartesianVector(lhs.GetX() - rhs.GetX(), lhs.GetY() - rhs.GetY(), lhs.GetZ() - rhs.GetZ());
}

//------------------------------------------------------------------------------------------------------------------------------------------

std::ostream &operator<<(std::ostream & stream, const CartesianVector& cartesianVector)
{
    stream  << " CartesianVector: " << std::endl
            << "    x:   " << cartesianVector.GetX() << std::endl
            << "    y:   " << cartesianVector.GetY() << std::endl
            << "    z:   " << cartesianVector.GetZ() << std::endl
            << " length: " << cartesianVector.GetMagnitude() << std::endl;

    return stream;
}

} // namespace pandora