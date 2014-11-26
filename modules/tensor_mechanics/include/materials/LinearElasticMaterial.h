// Original class author: A.M. Jokisaari,  O. Heinonen

#ifndef LINEARELASTICMATERIAL_H
#define LINEARELASTICMATERIAL_H

#include "TensorMechanicsMaterial.h"

/**
 * LinearElasticMaterial handles a fully anisotropic, single-crystal material's elastic
 * constants.  It takes all 21 independent stiffness tensor inputs, or only 9, depending on the
 * boolean input value given.  This can be extended or simplified to specify HCP, monoclinic,
 * cubic, etc as needed.
 */
class LinearElasticMaterial : public TensorMechanicsMaterial
{
public:
  LinearElasticMaterial(const std::string & name, InputParameters parameters);

protected:
  virtual void computeQpStrain();
  virtual void computeQpStress();
  virtual RankTwoTensor computeStressFreeStrain();

private:
  VariableValue & _T;

  const Real _T0;
  Real _thermal_expansion_coeff;

  std::vector<Real> _applied_strain_vector;
  RankTwoTensor _applied_strain_tensor;
};

#endif //LINEARELASTICMATERIAL_H
