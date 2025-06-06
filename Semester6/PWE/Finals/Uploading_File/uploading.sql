-- phpMyAdmin SQL Dump
-- version 3.4.5
-- http://www.phpmyadmin.net
--
-- Host: localhost
-- Generation Time: Feb 12, 2015 at 08:30 PM
-- Server version: 5.5.16
-- PHP Version: 5.3.8

SET SQL_MODE="NO_AUTO_VALUE_ON_ZERO";
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8 */;

--
-- Database: `uploading`
--

-- --------------------------------------------------------

--
-- Table structure for table `info`
--

CREATE TABLE IF NOT EXISTS `info` (
  `id` int(5) NOT NULL AUTO_INCREMENT,
  `name` varchar(20) NOT NULL,
  `pic_name` varchar(50) NOT NULL,
  PRIMARY KEY (`id`)
) ENGINE=InnoDB  DEFAULT CHARSET=utf8 AUTO_INCREMENT=22 ;

--
-- Dumping data for table `info`
--

INSERT INTO `info` (`id`, `name`, `pic_name`) VALUES
(8, 'yes sir', '1417532519_Business Intellegent (Jamshaid).pptx'),
(9, 'zeeshan', '1417532598_Assignment.docx'),
(10, 'ali', '1417533063_Microsoft Dynamics (Bilal).pptm'),
(11, 'shanishani', '1417533341_Assignment.docx'),
(12, 'zeeshan ramzan', '1417533399_1. Enterprise Resource Planning Systems'),
(13, 'zeeshan ramzan', '1417597013_1. Enterprise Resource Planning Systems'),
(14, 'ramzan', '1417704665_2. Microsoft Dynamics (Bilal).pptm'),
(15, 'farhan', '1418050304_Links.txt'),
(16, 'Rana', '1418114294_canvas.html'),
(17, 'ramzzn', '1418115051_canvas.html'),
(18, 'abubakar', '1418115503_marquee.html'),
(19, 'shani', '1418115592_SVG.html'),
(20, 'shani', '1422363175_100_7256.JPG'),
(21, 'tanzeel', '1422523815_connect.php');

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
