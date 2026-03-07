//    Copyright 2023 Christoph Hellmann Santos
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <https://www.gnu.org/licenses/>.
//

#ifndef CANOPEN_402_DRIVER__402_DRIVER_INTERFACE_HPP_
#define CANOPEN_402_DRIVER__402_DRIVER_INTERFACE_HPP_
#include "canopen_base_driver/lely_driver_bridge.hpp"
#include "canopen_core/driver_node.hpp"

namespace ros2_canopen
{
/**
 * @brief Abstract Class for a CANopen Device Node
 *
 * This class provides the base functionality for creating a
 * CANopen device node. It provides callbacks for nmt and rpdo.
 */
class Cia402DriverInterface : public ros2_canopen::CanopenDriver
{

public:
  Cia402DriverInterface(rclcpp::NodeOptions node_options = rclcpp::NodeOptions()) : CanopenDriver(node_options) {}

  virtual bool reset_node_nmt_command();
  
  virtual bool start_node_nmt_command();
  
  virtual bool tpdo_transmit(ros2_canopen::COData & data);
  
  virtual bool sdo_write(ros2_canopen::COData & data);

  virtual bool sdo_read(ros2_canopen::COData & data);

  virtual void register_nmt_state_cb(std::function<void(canopen::NmtState, uint8_t)> nmt_state_cb);

  virtual void register_rpdo_cb(std::function<void(COData, uint8_t)> rpdo_cb);

  virtual double get_effort();

  virtual double get_speed();

  virtual double get_position();

  virtual bool set_target(double target);

  virtual bool init_motor();

  virtual bool recover_motor();

  virtual bool halt_motor();

  virtual uint16_t get_mode();

  virtual bool set_operation_mode(uint16_t mode);
  
};
}  // namespace ros2_canopen

#endif  // CANOPEN_402_DRIVER__CANOPEN_402_DRIVER_HPP_
