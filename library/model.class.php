<?php
class Model extends SQLQuery {
	protected $_model;

	
	function __construct($DB_HOST=DB_HOST,$DB_USER=DB_USER,$DB_PASSWORD=DB_PASSWORD,$DB_NAME=DB_NAME) {

		$this->connect($DB_HOST,$DB_USER,$DB_PASSWORD,$DB_NAME);
		$this->_model = get_class($this);
		$this->_table = strtolower($this->_model)."s";
	}

	function __destruct() {
	}
}
