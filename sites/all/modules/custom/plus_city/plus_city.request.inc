<?php

/**
 * @file
 * API for making call to TAPI.
 */

/**
 * Request object for TAPI.
 */
class PlusTAPI {

  function __construct() {
    // TO DO
  }

  /**
   * Performs an API request using HTTP method.
   *
   * @param $call
   *  name of the API call being made.
   * @param $options
   *  (optional) an array taking the following keys:
   *  - params: (optional) an associative array of parameters to be sent along with the call. The key should be the name of the parameter and the value of that key should be the value to be passed for that parameter.
   * @return same as response returned by drupal_http_request().
   */
  function http_request($call, $options = array()) {
    $params = array();
    if (isset($options['params'])) {
      foreach ($options['params'] as $param => $value) {
        $params[$param] = $value;
      }
    }
    $query = http_build_query($params);
    $options['http_request_options'] = array();
    if (!empty($options['headers'])) {
      foreach ($options['headers'] as $header => $value) {
        list($header_key, $header_value) = explode(":", $value);
        $options['http_request_options']['headers'][$header_key] = $header_value;
      }
    }

    $response = drupal_http_request($call . '?' . $query, $options['http_request_options']);

    return $response;
  }

  /**
   * Performs an API request using cURL method.
   *
   * @param $call
   *  name of the API call being made.
   * @param $options
   *  (optional) an array taking the following keys:
   *  - params: (optional) an associative array of parameters to be sent along with the call. The key should be the name of the parameter and the value of that key should be the value to be passed for that parameter.
   * @return json formatted response returned by curl_exec().
   */
  function curl_request($call, $options = array()) {
    $params = array();
    if (!empty($options['params'])) {
      foreach ($options['params'] as $param => $value) {
        $params[$param] = $value;
      }
    }
    $query = drupal_http_build_query($params);

    if (!empty($options['headers'])) {
      $customHeader = array();
      foreach ($options['headers'] as $header => $value) {
        $customHeader[] = $value;
      }
    }

    $url = $call . '?' . $query;
    $ch = curl_init($url);
    $timeout = 0; // set to zero for no timeout
    curl_setopt($ch, CURLOPT_URL, $url);
    curl_setopt($ch, CURLOPT_SSL_VERIFYHOST, 0);
    curl_setopt($ch, CURLOPT_SSL_VERIFYPEER, false);
    curl_setopt($ch, CURLOPT_RETURNTRANSFER, 1);
    curl_setopt($ch, CURLOPT_FOLLOWLOCATION, 1);
    curl_setopt($ch, CURLOPT_HTTPHEADER, $customHeader);
    $response = curl_exec($ch);
    curl_close($ch);

    return drupal_json_decode($response);
  }
}
