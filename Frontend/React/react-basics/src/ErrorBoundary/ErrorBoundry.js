import React, { Component } from "react";

class ErrorBoundary extends Component {
  state = {
    has_error: false,
    error_message: "",
  };

  componentDidCatch = (error, error_info) => {
    this.setState({ has_error: true, error_message: error });
  };

  render() {
    if (this.state.has_error) {
      return <h1>Something Wong</h1>;
    } else {
      return this.props.children;
    }
  }
}

export default ErrorBoundary;
