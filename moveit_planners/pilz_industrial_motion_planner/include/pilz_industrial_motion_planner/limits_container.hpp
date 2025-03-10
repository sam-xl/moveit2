/*********************************************************************
 * Software License Agreement (BSD License)
 *
 *  Copyright (c) 2018 Pilz GmbH & Co. KG
 *  All rights reserved.
 *
 *  Redistribution and use in source and binary forms, with or without
 *  modification, are permitted provided that the following conditions
 *  are met:
 *
 *   * Redistributions of source code must retain the above copyright
 *     notice, this list of conditions and the following disclaimer.
 *   * Redistributions in binary form must reproduce the above
 *     copyright notice, this list of conditions and the following
 *     disclaimer in the documentation and/or other materials provided
 *     with the distribution.
 *   * Neither the name of Pilz GmbH & Co. KG nor the names of its
 *     contributors may be used to endorse or promote products derived
 *     from this software without specific prior written permission.
 *
 *  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 *  "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 *  LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
 *  FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
 *  COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
 *  INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
 *  BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
 *  LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 *  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 *  LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
 *  ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 *  POSSIBILITY OF SUCH DAMAGE.
 *********************************************************************/

#pragma once

#include <pilz_industrial_motion_planner/joint_limits_container.hpp>
#include <math.h>

#include <pilz_industrial_motion_planner/cartesian_limits_parameters.hpp>

namespace pilz_industrial_motion_planner
{
/**
 * @brief This class combines CartesianLimit and JointLimits into on single
 * class.
 */
class LimitsContainer
{
public:
  LimitsContainer();

  /**
   * @brief Return if this LimitsContainer has defined joint limits
   * @return True if container contains joint limits
   */
  bool hasJointLimits() const;

  /**
   * @brief Set joint limits
   * @param joint_limits
   */
  void setJointLimits(JointLimitsContainer& joint_limits);

  /**
   * @brief Obtain the Joint Limits from the container
   * @return the joint limits
   */
  const JointLimitsContainer& getJointLimitContainer() const;

  /**
   * @brief Prints the cartesian limits set by user. Default values for limits are 0.0
   */
  void printCartesianLimits() const;

  /**
   * @brief Set cartesian limits
   * @param cartesian_limit
   */
  void setCartesianLimits(cartesian_limits::Params& cartesian_limit);

  /**
   * @brief Return the cartesian limits
   * @return the cartesian limits
   */
  const cartesian_limits::Params& getCartesianLimits() const;

private:
  /// Flag if joint limits where set
  bool has_joint_limits_;

  /// The joint limits
  JointLimitsContainer joint_limits_;

  /// Flag if cartesian limits have been set
  bool has_cartesian_limits_;

  /// The cartesian limits
  cartesian_limits::Params cartesian_limits_;
};

}  // namespace pilz_industrial_motion_planner
