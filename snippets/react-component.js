import React from 'react';
import { View, StyleSheet, ...  } from 'react-native';

const styles = StyleSheet.create({ hidden: { opacity: 0, }, });

class Modal extends React.Component {
  constructor(props) {
    super(props);
    this.state = { x: false, };
    this.initX = props.x;
  }

  componentDidMount() { }
  componentWillReceiveProps(nextProps) { if (nextProps.open !== this.props.open) { ...  } }
  componentDidUpdate() { }
  componentWillUnmount() { }
  turnOnModal = () => { ...  };

  render() { return ( <View ...  > </View>); }
}

Modal.propTypes = {
  setRef: React.PropTypes.func,
};

Modal.defaultProps = { open: false, };

export default Modal;
