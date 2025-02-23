mindquantum.core.circuit.partial_psi_psi
=========================================

.. py:function:: mindquantum.core.circuit.partial_psi_psi(circuit: Circuit, backend='mqvector')

    根据给定参数化量子线路，计算矩阵：

    .. math::

        B_i = \frac{\partial \left<\psi\right| }{\partial x_i}\left|\psi\right>

    参数：
        - **circuit** (Circuit) - 一个给定的参数化量子线路。
        - **backend** (str) - 一个受支持的量子模拟器后端。请参考 :class:`~.simulator.Simulator` 的描述。默认值： ``'mqvector'``。

    返回：
        Function，一个函数，该函数输入参数化量子线路的值，返回量子态对不同参数的导数与量子态本身的内积。
