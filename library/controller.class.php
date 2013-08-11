<?php
class Controller {

	protected $_model;
	protected $_controller;
	protected $_action;
	protected $_template;

	function __construct($model, $controller, $action, $viewVersion) {

		$this->_controller = $controller;
		$this->_action = $action;
		$this->_model = $model;
		$this->$model = new $model;
		$this->_template = new Template($controller,$action, $viewVersion);

	}

	function set($name,$value) {
		$this->_template->set($name,$value);
	}

	function __destruct() {
			$this->_template->render();
	}

}
