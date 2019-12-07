const getScreenSize = require('../build/Debug/testlib.node');

console.log(getScreenSize());

describe('getScreenSize()', () => {
  test('Can get the real screen size', () => {
    const screenSize = getScreenSize();
    expect(screenSize.width).toBeGreaterThan(0);
    expect(screenSize.height).toBeGreaterThan(0);
  });
});
