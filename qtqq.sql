/*
Navicat MySQL Data Transfer

Source Server         : long
Source Server Version : 50714
Source Host           : localhost:3306
Source Database       : qtqq

Target Server Type    : MYSQL
Target Server Version : 50714
File Encoding         : 65001

Date: 2021-02-20 11:56:31
*/

SET FOREIGN_KEY_CHECKS=0;

-- ----------------------------
-- Table structure for tab_accounts
-- ----------------------------
DROP TABLE IF EXISTS `tab_accounts`;
CREATE TABLE `tab_accounts` (
  `employeeID` int(20) NOT NULL COMMENT '员工工号',
  `account` char(20) NOT NULL COMMENT '账号',
  `code` char(20) NOT NULL COMMENT '密码',
  PRIMARY KEY (`account`)
) ENGINE=MyISAM DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of tab_accounts
-- ----------------------------
INSERT INTO `tab_accounts` VALUES ('10001', 'renyi', 'renyi');
INSERT INTO `tab_accounts` VALUES ('10002', 'rener', 'rener');
INSERT INTO `tab_accounts` VALUES ('10003', 'rensan', 'rensan');
INSERT INTO `tab_accounts` VALUES ('10004', 'yanyi', 'yanyi');
INSERT INTO `tab_accounts` VALUES ('10005', 'yaner', 'yaner');
INSERT INTO `tab_accounts` VALUES ('10006', 'yansan', 'yansan');
INSERT INTO `tab_accounts` VALUES ('10007', 'shiyi', 'shiyi');
INSERT INTO `tab_accounts` VALUES ('10008', 'shier', 'shier');
INSERT INTO `tab_accounts` VALUES ('10009', 'shisan', 'shisan');

-- ----------------------------
-- Table structure for tab_department
-- ----------------------------
DROP TABLE IF EXISTS `tab_department`;
CREATE TABLE `tab_department` (
  `departmentID` int(11) NOT NULL AUTO_INCREMENT COMMENT '公司部门号（部门群号）',
  `department_name` char(20) NOT NULL COMMENT '部门名称',
  `picture` char(50) NOT NULL COMMENT '部门头像路径',
  `sign` char(100) NOT NULL COMMENT '部门口号',
  PRIMARY KEY (`departmentID`)
) ENGINE=MyISAM AUTO_INCREMENT=2004 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of tab_department
-- ----------------------------
INSERT INTO `tab_department` VALUES ('2000', '公司群', 'D:\\qtqq_image\\gsq.png', '越分享越拥有');
INSERT INTO `tab_department` VALUES ('2001', '人事部', 'D:\\qtqq_image\\rsb.png', '公心');
INSERT INTO `tab_department` VALUES ('2002', '研发部', 'D:\\qtqq_image\\yfb.png', 'c++牛逼');
INSERT INTO `tab_department` VALUES ('2003', '市场部', 'D:\\qtqq_image\\scb.ong', '努力找工作');

-- ----------------------------
-- Table structure for tab_employees
-- ----------------------------
DROP TABLE IF EXISTS `tab_employees`;
CREATE TABLE `tab_employees` (
  `departmentID` int(11) NOT NULL COMMENT '群ID，群号',
  `employeeID` int(11) NOT NULL AUTO_INCREMENT COMMENT '工号，员工qq号',
  `employee_name` char(20) NOT NULL COMMENT '员工姓名',
  `employee_sign` char(200) DEFAULT NULL COMMENT '员工签名',
  `status` tinyint(4) NOT NULL DEFAULT '1' COMMENT '1有效 0注销',
  `picture` char(150) NOT NULL COMMENT '员工头像路径',
  `online` tinyint(4) NOT NULL DEFAULT '1' COMMENT '在线状态 1离线 2在线',
  PRIMARY KEY (`employeeID`)
) ENGINE=MyISAM AUTO_INCREMENT=10011 DEFAULT CHARSET=utf8;

-- ----------------------------
-- Records of tab_employees
-- ----------------------------
INSERT INTO `tab_employees` VALUES ('2001', '10001', 'renyi', '分一样的女子', '0', 'D:\\qtqq_image\\r1.png', '1');
INSERT INTO `tab_employees` VALUES ('2001', '10002', 'rener', '奋斗中', '0', 'D:\\qtqq_image\\r2.png', '1');
INSERT INTO `tab_employees` VALUES ('2001', '10003', 'rensan', '加油', '1', 'D:\\qtqq_image\\r3.png', '1');
INSERT INTO `tab_employees` VALUES ('2002', '10004', 'yanyi', '调bug中', '1', 'D:\\qtqq_image\\r1.png', '1');
INSERT INTO `tab_employees` VALUES ('2002', '10005', 'yaner', '改bug中', '1', 'D:\\qtqq_image\\r2.png', '1');
INSERT INTO `tab_employees` VALUES ('2002', '10006', 'yansan', '写bug中', '1', 'D:\\qtqq_image\\r3.png', '1');
INSERT INTO `tab_employees` VALUES ('2003', '10007', 'shiyi', '跑市场中', '1', 'D:\\qtqq_image\\r1.png', '1');
INSERT INTO `tab_employees` VALUES ('2003', '10008', 'shier', '目标明确，坚定不够', '1', 'D:\\qtqq_image\\r2.png', '1');
INSERT INTO `tab_employees` VALUES ('2003', '10009', 'shisan', '周末休息', '1', 'D:\\qtqq_image\\r3.png', '1');
