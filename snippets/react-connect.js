export const requestToken = createAction( ... );
import { requestToken } from '../../actions/user';

const mapStateToProps = createStructuredSelector({
  fun1: longfun1,
  fun2,
});

const mapDispatchToProps = {
  requestToken,
};

export default connect(mapStateToProps, mapDispatchToProps)(LoginContainer);
